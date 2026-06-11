#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vi a(N+1);;
    for(int i=0;i<N-1;i++){
        int temp;
        cin >> temp;
        a[temp]++;
    }
    for(int i=1;i<=N;i++){
        cout << a[i] << endl;
    }
    return 0;
}