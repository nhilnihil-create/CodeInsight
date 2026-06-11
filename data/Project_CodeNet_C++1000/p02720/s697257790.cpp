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

set<lint> lun;
void lunmake(string x,int depth,int last){
    if(depth>0){
        for(int i=max(last-1,0);i<=min(last+1,9);i++){
            lun.insert(stoll(x+str(i)));
            lunmake(x+str(i),depth-1,i);
        }
    }
}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    int n;cin>>n;
    for(int i=1;i<10;i++){
        lun.insert(i);
        lunmake(str(i),10,i);
    }
    for(auto x:lun){
        n--;
        if(n==0)cout<<x<<endl;
    }
}
