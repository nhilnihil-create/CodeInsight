#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int n, m, h[100000], a[100000], b[100000];
    bool good[100000];
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> h[i];
        good[i] = true;
    }

    for(int i=0; i<m; i++){
        cin >> a[i] >> b[i];
    }

    int answer = 0;
    
    for(int i=0; i<m; i++){
        good[ a[i]-1 ] &= h[ a[i]-1 ] > h[ b[i]-1 ];
        good[ b[i]-1 ] &= h[ a[i]-1 ] < h[ b[i]-1 ];
    }
    
    for(int i=0; i<n; i++){
        answer += int(good[i]);
    }

    cout << answer;

}