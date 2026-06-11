//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1<<30;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};

// //dijkstraの負も出来る版
// //O(V*E)  V:頂点数,E:辺の数
// //close=trueの時、負の閉路に到達
// using T=tuple<int,int,int>;
// const int MAX_dist=1e9;
// vector<T> graph(0);//from,to,cost
// vector<int> d(0);
// int V,E;//V:頂点数,E:辺の数
// bool close=false;

// void init(int n){//辺をgraphに入れた後に
//     d.resize(n,MAX_dist);
//     V =n;
// }

// void Bellman(int s){//s:始点
//     E=graph.size();
//     d[s]=0;
//     int close_cnt=0;
//     close=false;
//     while(1){//V回以上のループで負閉路に到達
//         close_cnt ++;
//         bool update=0;
//         for(auto e: graph){
//             int from,to,cost;
//             tie(from,to,cost)=e;
//             if(d[from]!=MAX_dist && d[to]>d[from]+cost){
//                 update =true;
//                 d[to]=d[from]+cost;
//             }
//         }
//         if(!update) break;
//         if(close_cnt==V){ close=true;break;}
//     }
// }

//dijkstraの負も出来る版
//O(V*E)  V:頂点数,E:辺の数
//close=trueの時、負の閉路に到達
using T=tuple<int,int,int>;
const int MAX_dist=1e9;
vector<T> graph(0);//from,to,cost
vector<int> d(0);
int V,E;//V:頂点数,E:辺の数
bool close=false;

void init(int n){//辺をgraphに入れた後に
    d.resize(n,MAX_dist);
    V =n;
}

void Bellman(int s){//s:始点
    E=graph.size();
    d[s]=0;
    int close_cnt=0;
    close=false;
    while(1){//V回以上のループで負閉路に到達
        close_cnt ++;
        bool update=0;
        for(auto e: graph){
            int from,to,cost;
            tie(from,to,cost)=e;
            if(d[from]!=MAX_dist && d[to]>d[from]+cost){
                update =true;
                d[to]=d[from]+cost;
            }
        }
        if(!update) break;
        if(close_cnt==V){ close=true;break;}
    }
}

int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    int v,e,r;
    cin>>v>>e>>r;
    init(v);
    int s,t,c;
    rep(i,e){
        cin>>s>>t>>c;
        graph.emplace_back(s,t,c);
    }
    Bellman(r);
    if(close) cout<<"NEGATIVE CYCLE"<<endl;
    else{
        rep(i,v){
            if(d[i]==MAX_dist) cout<<"INF"<<endl;
            else cout<<d[i]<<endl;
        }
    }
}
