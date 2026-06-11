/*
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B
    ????§£???????????????


#include <iostream>
using namespace std;
int main() {
    int n,x;
    int ans;
    while(cin >> n >> x,(n!=0)||(x!=0)){
        ans = 0;
        for(int a = 1;a <= n;a++){ //a = a+1
            for(int b = a+1;b <= n;b++){
                for(int c = b+1; c <= n;c++){
                    if(a+b+c==x)ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}


#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#define rep(i,n) for(int i = 0;i < n;i++)
#define fs first
#define sc second
#define mp make_pair
using namespace std;

int N,M;
int row,line;
double table[105][105]={0};
vector<pair<int,double> > G[105]; //??????????????????

void show(){
    rep(i,N){
        rep(j,N+1){
            printf("%5.8f ",table[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    cin >> N >> M;
    int from,to;
    double r;
    rep(i,M){
        cin >> from >> to >> r;
        from--;
        to--;
        G[from].push_back(mp(to,r));
        G[to].push_back(mp(from,r));
    }
    table[0][0]=1.0;
    table[N-1][N]=-1.0;
    for(int i = 1;i < N;i++){
        rep(j,G[i].size()){
            table[i][G[i][j].fs]+=1.0/G[i][j].sc;
            table[i][i]-=1.0/G[i][j].sc;
        }
    }
    rep(i,N){
        double max = 0.0;
        int mrow = i;
        for(int j=i;j<N;j++){
            if(fabs(table[j][i])>max){
                max = fabs(table[j][i]);
                mrow = j;
            }
        }
        if(i!=mrow){
            rep(j,N+1){
                double temp = table[i][j];
                table[i][j]=table[mrow][j];
                table[mrow][j]=temp;
            }
        }
        double now = table[i][i];
        rep(k,N+1){
            table[i][k]/=now;
        }
        rep(j,N){
            if(i==j)
                continue;
            double base = table[j][i];
            for(int k = i;k < N+1;k++){
                table[j][k]-=table[i][k]*base;
            }
        }
    }
    printf("%.2f\n",((int)(table[N-1][N]*100.0+0.5))/100.0);

    return 0;
    
}*/

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;



int main(){
    int N,M;
    while(cin >> N >> M,(N!=0)||(M!=0)){
        int h_[1505];
        int w_[1505];
        int hsz,wsz;
        vector<int> h,w;
        rep(i,N){
            scanf("%d",h_+i);
        }
        rep(i,M){
            scanf("%d",w_+i);
        }
        for(int i=1;i<=N;i++){
            int hoge = 0;
            rep(j,i){
                hoge += h_[j];
            }
            h.push_back(hoge);
            rep(j,N-i){
                hoge -= h_[j];
                hoge += h_[j+i];
                h.push_back(hoge);
            }
        }
        for(int i= 1;i <=M;i++){
            int hoge = 0;
            rep(j,i){
                hoge += w_[j];
            }
            w.push_back(hoge);
            rep(j,M-i){
                hoge -= w_[j];
                hoge += w_[j+i];
                w.push_back(hoge);
            }
        }
        sort(h.begin(),h.end());
        sort(w.begin(),w.end());
        hsz = (int)h.size();
        wsz = (int)w.size();
        
        int temp = -1;
        map<int,int> hm,wm;
        rep(i,hsz){
            if(i == hsz-1 || h[i]!=h[i+1]){
                hm[h[i]]=i-temp;
                temp = i;

            }
        }
        temp = -1;
        rep(i,wsz){
            if(i == wsz-1 || w[i]!=w[i+1]){
                wm[w[i]]=i-temp;
                temp = i;
            }
        }
        int ans = 0;
        map<int,int>::iterator it = hm.begin();
        while(it!=hm.end()){
            int l = it->first;
            if(wm.find(l)!=wm.end()){
                ans += it->second*wm[l];
            }
            it++;
        }
        printf("%d\n",ans);
    }
    return 0;
}