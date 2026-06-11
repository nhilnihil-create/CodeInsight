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

string a, b;

int main(){
    IOS

    cin>>a, b = a;

    reverse(all(b));
    
    int cont = 0;

    fore(i,0,(int)a.size()/2){
        if(a[i]!=b[i]) cont++;
    }

    cout<<cont;

    return 0;
}