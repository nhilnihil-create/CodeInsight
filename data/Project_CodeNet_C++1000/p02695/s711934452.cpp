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

int n,m,q,ans=0;
vector<int> a(0);
vector<int> b(0);
vector<int> c(0);
vector<int> d(0);
vector<int> suretu(11,0);

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    int A,B,C,D;
    cin>>n>>m>>q;
    for(int i=0;i<q;i++){
        cin>>A>>B>>C>>D;
        a.pb(A);b.pb(B);c.pb(C);d.pb(D);
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        for(int i2=i;i2<=m;i2++){
            for(int i3=i2;i3<=m;i3++){
                for(int i4=i3;i4<=m;i4++){
                    for(int i5=i4;i5<=m;i5++){
                        for(int i6=i5;i6<=m;i6++){
                            for(int i7=i6;i7<=m;i7++){
                                for(int i8=i7;i8<=m;i8++){
                                    for(int i9=i8;i9<=m;i9++){
                                        for(int i10=i9;i10<=m;i10++){
                                            int tmp=0;
                                            vector<int> vec={i,i2,i3,i4,i5,i6,i7,i8,i9,i10};
                                            for(int j=0;j<q;j++){
                                                if(vec[b[j]-1]-vec[a[j]-1]==c[j])tmp+=d[j];
                                            }
                                            ans=max(ans,tmp);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
