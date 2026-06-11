#include<bits/stdc++.h>
#define Abra_Ka_Dabra ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    Abra_Ka_Dabra
    string n;
    cin>>n;
    for(int i=0; i<n.size(); i++){
        if(n[i]=='7'){
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";

    return 0;
}
