#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
const long long INF=1145141919,MOD=1e9+7;
const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};
const double EPS = 1e-9;    // 許容誤差。問題によって変える
//typedef complex<double> P;  // Point
//typedef vector<P> VP; //単純多角形
//#define X real()
//#define Y imag()
//#define LE(n,m) ((n) < (m) + EPS)
//#define GE(n,m) ((n) + EPS > (m))
//#define EQ(n,m) (abs((n)-(m)) < EPS)
//namespace std{
//    bool operator < (const P a, const P b){
//        return a.X != b.X ? a.X <b.X : a.Y < b.Y;
//    }
//}
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
//外積cross(a,b) = |a||b|sinθ
//double cross(const P& a, const P& b) {
 // return imag(conj(a)*b);
//}
//内積dot(a,b) = |a||b|cosθ
//double dot(const P& a, const P& b) {
  //return real(conj(a)*b);
//}
//Line
//struct L : public vector<P> {
  //L(const P &a, const P &b) {
    //push_back(a); push_back(b);
  //}
//};
//円
//struct C{
//  P p; double r;
//  C(const P &p, double r) : p(p), r(r) { }
//};
int main(){
    int m,nmin,nmax;
    cin>>m>>nmin>>nmax;
    while(m){
        int score[m]={},line=-INF,ans=0;
        for(int i=0;i<m;i++){
            cin>>score[i];
        }
        for(int i=nmin-1;i<nmax;i++){
            if(line<=score[i]-score[i+1]){
                line=score[i]-score[i+1];
                ans=i+1;
            }
        }
        cout<<ans<<endl;
        cin>>m>>nmin>>nmax;
    }
    return 0;
}

