#include <bits/stdc++.h>
using namespace std;

#define MOD 10000007
#define f first
#define s second
#define es " "
#define pb push_back
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define ll long long int
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define sz(x) (int)x.size()

int main(){
    fastio;
    set<int> letras[1005];
    string total, wanted;
    cin >> total >> wanted;
    for(int i=0; i<sz(total); i++){
        letras[(int)total[i]].insert(i+1);
    }
    ll resp=0;
    int pos=-1;
    for(int i=0; i<sz(wanted); i++){
        int letra=(int)wanted[i];
        if(sz(letras[letra])==0){
            cout << -1 << endl;
            return 0;
        }
        set<int>::iterator it=letras[letra].upper_bound(pos);
        if(it==letras[letra].end()){
            resp+=(sz(total)-pos)+*letras[letra].begin();
            pos=*letras[letra].begin();
        }else{
            resp+=*it-pos;
            pos=*it;
        }
    }
    cout << resp-1 << endl;
    return 0;
}