#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;

int main(){
    int N;
    cin >> N;
    vi a(N);
    for(int i=0;i<N;i++) cin >> a[i];
    int all=0;
    for(int i=0;i<N;i++) all^=a[i];
    for(int i=0;i<N;i++){
        int c=all^a[i];
        cout << c << endl;
    }
    return 0;
}