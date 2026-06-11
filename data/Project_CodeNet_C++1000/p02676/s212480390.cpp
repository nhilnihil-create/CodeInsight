#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;
#define w(x) cout << (#x) << " is " << x << "\n" ;

int main()
{
    //fast ;
//#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//#endif
    int k,i;
    string s;
    cin >> k >> s ;
    if(s.size()<=k)
        cout << s <<"\n";
    else
    {
        for(i=0 ; i<k ; i++)
            cout << s[i];
        cout << "...\n";
    }
    return 0;
}
