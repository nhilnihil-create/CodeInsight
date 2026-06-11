#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    int h,w,a,b;cin>>h>>w>>a>>b;
    vector<vector<int>> vec(h,vector<int>(w,0));
    vector<pair<int,int>> W(w,pair<int,int>(0,0)),H(h,pair<int,int>(0,0));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(min(W[j].first+1,W[j].second)>b||W[j].first+1>h-b){vec[i][j]=1;W[j].second++;H[i].second++;}
            else if(min(W[j].first,W[j].second+1)>b||W[j].second+1>h-b){vec[i][j]=0;W[j].first++;H[i].first++;}
            else if(min(H[i].first+1,H[i].second)>a||H[i].first+1>w-a){vec[i][j]=1;W[j].second++;H[i].second++;}
            else if(min(H[i].first,H[i].second+1)>a||H[i].second+1>w-a){vec[i][j]=0;W[j].first++;H[i].first++;}
            else{
                if(j%2==0){
                    vec[i][j]=1;W[j].second++;H[i].second++;
                }
                else{
                    vec[i][j]=0;W[j].first++;H[i].first++;
                }
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<vec[i][j];
        }
        cout<<endl;
    }
}
