#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define fore(i,x,n) for(int i=x;i<n;i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define ordenar(a) sort(all(a))
typedef long long ll;
typedef vector<int> vi;

int n;
string a;

int main(){
    IOS
    
    cin>>n>>a;

    fore(i,0,a.size()){
        cout<<(char)('A'+((a[i]-'A')+n)%26);
    }
    
    return 0;
}