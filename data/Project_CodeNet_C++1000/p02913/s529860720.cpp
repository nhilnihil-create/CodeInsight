// ABC141-E
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=s.size();
    int ans=0;
    for(int i=0;i<=l-2;i++){ //i文字目から始まる文字列と、後ろの文字列の共通部分を探す。
        // z-algorithm
        vector<int> z(l-i,0);
        z[0]=l-i;
        int from=-1,end=-1;
        for(int j=i+1;j<=l-1;j++){
            int &same=z[j-i];
            if(from!=-1){
                same=min(z[(j-i)-(from-i)],end-(j-1));
                same=max(0,same);
            }
            while(j+same<=l-1 && s[i+same]==s[j+same]) same++;
            // 1つ目の末尾と2つ目の先頭が重ならないmax(共通部分)
            int cur=0;
            if(same!=0){
                if((i-1)+same<j) cur=same;
                else cur=j-i;
            }
            
            ans=max(ans,cur);
            if(end<j+same-1){
                from=j;
                end=j+same-1;
            }
        }
        //cout<<z<<endl;
    }
    cout<<ans<<endl;
    return 0;
}