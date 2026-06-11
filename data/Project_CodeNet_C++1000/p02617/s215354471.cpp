#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

//Some constants don't work
#ifndef INT_MAX
#define INT_MAX 2147483647
#endif
#ifndef INT_MIN
#define INT_MIN -2147483648
#endif
//short hand tricks
typedef long long ll;

using namespace std;

ll N;

int main(int argc, char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> N;
    //important idea a vertice of a tree by itself adds exactly 1 disconnected component
    //and an edge of a tree is essential so it takes 2 disconnected components and turns them into one
    //count the number of ranges each vertice is included in - (number of ranges each edge is contained in)
    ll vranges = 0;
    for(int i=1; i<=N; i++) {
        //pick left then pick right
        ll left = i;
        ll right = (N-i)+1;
        vranges+=(left*right);
    }
    ll eranges = 0;
    for(int i=0; i<N-1; i++) {
        int v,u;
        cin >> v >> u;
        int l = min(u,v);
        int r = max(u,v);
        ll left = l;
        ll right = (N-r)+1;
        eranges+=(left*right);
    }
    cout << (vranges-eranges) << "\n";
    
    return 0;
}
