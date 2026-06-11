#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define In_The_Name_Of_Allah_The_Merciful ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Alhamdulillah return 0;
#define all(v) v.begin(),v.end()
#define debug(n) cerr << "[" << #n << " = " << n << "]" << endl 

void Suhaib_Sawalha (){

    string s , w;
    cin >> s >> w;

    vector <int> st[26];
    vector <int> :: iterator it;

    int n = s.size();
    for (int i = 0 ; i < n ; ++i)
        st[s[i]-'a'].push_back(i+1);

    for (char &c : w){
        if (st[c-'a'].empty()){
            cout << -1;
            return;
        }
    }

    int last = 0;
    ll ans = 0;
    for (char &c : w){
        it = upper_bound(all(st[c-'a']),last);
        if (it == st[c-'a'].end()){
            ++ans;
            it = st[c-'a'].begin();
        }
        last =  *it;
    }

    cout << ans * 1ll * (ll) n + 1ll * last;

}

int main(){
                                In_The_Name_Of_Allah_The_Merciful   /* بسم الله الرحمن الرحيم  */
#ifndef ONLINE_JUDGE
    freopen("SuhaibSawalha1.txt","r",stdin);
#endif
//int _;for(cin>>_;_;--_,cout<<'\n')
        Suhaib_Sawalha();
                                         Alhamdulillah                    /* الحمد لله */
}