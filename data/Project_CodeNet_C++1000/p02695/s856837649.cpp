#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const int inf = 1e9+7;
const int mod = 1e9+7;

int main(){
    int n,m,q,ans=0;
    cin>>n>>m>>q;

    vector<int>a(q),b(q),c(q),d(q),A(50);
    rep(i,q)cin>>a[i]>>b[i]>>c[i]>>d[i];

    for (int i1=1;i1<=m;i1++) {
        A[1]=i1;
        for (int i2=i1;i2<=m;i2++) {
            A[2]=i2;
            for (int i3=i2;i3<=m;i3++) {
                A[3]=i3;
                for (int i4=i3;i4<=m;i4++) {
                    A[4]=i4;
                    for (int i5=i4;i5<=m;i5++) {
                        A[5]=i5;
                        for (int i6=i5;i6<=m;i6++) {
                            A[6]=i6;
                            for (int i7=i6;i7<=m;i7++) {
                                A[7]=i7;
                                for (int i8=i7;i8<=m;i8++) {
                                    A[8]=i8;
                                    for (int i9=i8;i9<=m;i9++) {
                                        A[9]=i9;
                                        for (int i10=i9;i10<=m;i10++) {
                                            A[10]=i10;
                                            int sum=0;
                                            for(int i=0;i<q;i++){
                                                if(A[b[i]]-A[a[i]]==c[i]){
                                                    sum+=d[i];
                                                }
                                            }
                                            ans=max(sum,ans);
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
