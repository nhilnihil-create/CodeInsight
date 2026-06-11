#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define bigger (char)toupper
#define smaller (char)tolower
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int H,W,N;
    cin>>H>>W>>N;
    int a=max(H,W);
    if(N%a==0) cout<<N/a<<endl;
    else cout<<N/a+1<<endl;
}