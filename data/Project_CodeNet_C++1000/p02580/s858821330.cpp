#include<bits/stdc++.h>
using namespace std;
using Long = long long;
using pii = pair<int,int>;
#define ff first
#define ss second

int h , w , m;
map<int,int> H , W;
multiset<pii> S;

int main(){

    scanf("%d %d %d",&h,&w,&m);
    int x , y;
    int mx = 0 , my = 0;

    for( int i = 0 ; i < m ; ++i ){
        scanf("%d %d",&x,&y);
        H[x]++;
        W[y]++;
        S.insert({x,y});
        mx = max( mx , H[x] );
        my = max( my , W[y] );
    }

    vector<int> hh , ww;
    for( auto &it : H ) if( it.ss == mx ) hh.push_back(it.ff);
    for( auto &it : W ) if( it.ss == my ) ww.push_back(it.ff);

    int ans = mx + my ;
    for( int i : hh ){
        for( int j : ww ){
            if( !S.count({i,j}) ){
                printf("%d\n", ans);
                return 0;
            }
        }
    }
    printf("%d\n" , ans - 1);
    return 0;
}