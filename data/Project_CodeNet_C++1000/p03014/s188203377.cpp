// ABC129-D
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
namespace you {
    std::string to_string(char val) {
        return std::string(1, val);
        // return std::string{val};
        // you::to_string(char)
    }
}

int num=2010;
vector<vector<int>> h_wa(num,vector<int>(num)); //各行の累積和
vector<vector<int>> w_wa(num,vector<int>(num)); //各列の累積和
bool se(int i,int mid,int x,int w){
    if(mid<=-1) return false;
    if(w<=mid) return true;
    return h_wa[i][mid]<=x;
}
bool se2(int i,int mid,int x,int w){
    if(mid<=-1) return true;
    if(w<=mid) return false;
    return x<=h_wa[i][mid];
}
bool se3(int j,int mid,int x,int h){
    if(mid<=-1) return false;
    if(h<=mid) return true;
    return w_wa[j][mid]<=x;
}
bool se4(int j,int mid,int x,int h){
    if(mid<=-1) return true;
    if(h<=mid) return false;
    return x<=w_wa[j][mid];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    int h,w;
    cin>>h>>w;
    vector<vector<char>> info(h,vector<char>(w));
    rep(i,h){
        string s;
        cin>>s;
        rep(j,w) info[i][j]=s[j];
    }
    //cout<<info<<endl;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(j==0){
                if(info[i][j]=='#') h_wa[i][j]=1;
                else h_wa[i][j]=0;
            }else{
                if(info[i][j]=='#') h_wa[i][j]=h_wa[i][j-1]+1;
                else h_wa[i][j]=h_wa[i][j-1];
            }
        }
    }
    //cout<<h_wa<<endl;
    
    for(int i=0;i<w;i++){ //列
        for(int j=0;j<h;j++){ //行
            if(j==0){
                if(info[j][i]=='#') w_wa[i][j]=1;
                else w_wa[i][j]=0;
            }else{
                if(info[j][i]=='#') w_wa[i][j]=w_wa[i][j-1]+1;
                else w_wa[i][j]=w_wa[i][j-1];
            }
        }
    }
    //cout<<w_wa<<endl;

    int ans=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(info[i][j]=='#') continue; //自分が障害物なら調べない。
            int koho=0;
            int ok=-1,ng=w;
            while(ng-ok>1){
                int mid=(ok+ng)/2;
                if(se(i,mid,h_wa[i][j],w)) ok=mid;
                else ng=mid;
            }
            koho+=(ok-j);
            //cout<<i<<" "<<j<<" "<<ok<<endl;
            int ng2=-1,ok2=w;
            while(ok2-ng2>1){
                int mid=(ok2+ng2)/2;
                if(se2(i,mid,h_wa[i][j],w)) ok2=mid;
                else ng2=mid;   
            }
            if(info[i][ok2]=='#') ok2+=1;
            koho+=(j-ok2);
            //cout<<i<<" "<<j<<" "<<ok2<<endl;
            int ok3=-1,ng3=h;
            while(ng3-ok3>1){
                int mid=(ok3+ng3)/2;
                if(se3(j,mid,w_wa[j][i],h)) ok3=mid;
                else ng3=mid;   
            }
            koho+=(ok3-i);
            //cout<<j<<" "<<i<<" "<<ok3<<endl;
            int ok4=h,ng4=-1;
            while(ok4-ng4>1){
                int mid=(ok4+ng4)/2;
                if(se4(j,mid,w_wa[j][i],h)) ok4=mid;
                else ng4=mid;   
            }
            if(info[ok4][j]=='#') ok4+=1;
            //cout<<j<<" "<<i<<" "<<ok4<<endl;
            koho+=(i-ok4);
            koho+=1; //自分も入れる。
            if(ans<koho) ans=koho;
        }
    }
    cout<<ans<<endl;
    //cout<<w_wa[0]<<endl;
    return 0;
}