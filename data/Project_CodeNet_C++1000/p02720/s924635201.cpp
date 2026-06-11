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
    queue<lint> lun;
    int n;cin>>n;
    lint x;
    for(lint i=1;i<10;i++)lun.push(i);
    for(int i=0;i<n;i++){
        x=lun.front();lun.pop();
        if(x%10!=0)lun.push(x*10+(x%10)-1);
        lun.push(x*10+(x%10));
        if(x%10!=9)lun.push(x*10+(x%10)+1);
    }
    cout<<x<<endl;
}
