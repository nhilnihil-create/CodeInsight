#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define inf INT_MAX
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define mod 1000000009
#define ld long double
#define eps 1e-8
#define MAXN 2123
#define int long long

multiset<int> red;
multiset<int> green;

int32_t main (){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<setprecision(2)<<fixed;

    int r,g,nr,ng,nc;
    cin>>r>>g>>nr>>ng>>nc;
    for(int i=0;i<nr;i++){
        int x;
        cin>>x;
        red.insert(x);
    }
    for(int i=0;i<ng;i++){
        int x;
        cin>>x;
        green.insert(x);
    }
    while(red.size()>r)red.erase(red.begin());
    while(green.size()>g)green.erase(green.begin());
    for(int i=0;i<nc;i++){
        int x;
        cin>>x;
        if(red.size()<r){
            red.insert(x);
        }
        else if(green.size()<g){
            green.insert(x);
        }
        else{
            int pr=*red.begin();
            int pg=*green.begin();
            if(pr<pg && x>pr){
                red.erase(red.begin());
                red.insert(x);
            }
            else if(x>pg){
                green.erase(green.begin());
                green.insert(x);
            }
        }
    }
    int resp=0;
    for(auto x:red)resp+=x;
    for(auto x:green)resp+=x;
    cout<<resp<<endl;
    return 0;
}

