#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<pair<double,double>> vp(N);
    for(int i=0;i<N;i++){
        cin>>vp[i].first>>vp[i].second;
    }
    double ans=0;
    for(int i=0;i<N;i++){
        double gx=vp[i].first,gy=vp[i].second;
        for(int k=0;k<4;k++){
        double nx=-gy,ny=gx;
        gx=nx;
        gy=ny;
        double sx=0,sy=0;
        double px=0,qx=0;
        double py=0,qy=0;
        for(int j=0;j<N;j++){
            double dot = gx*vp[j].first+gy*vp[j].second;
            double cross=gx*vp[j].second-gy*vp[i].second;
            if(dot<0){
                continue;
            }
            if(dot>0){
                sx+=vp[j].first;
                sy+=vp[j].second;
            }else{
                if(cross>0){
                    px+=vp[j].first;
                    py+=vp[j].second;
                }else{
                    qx+=vp[j].first;
                    qy+=vp[j].second;
                }
            }
        }
         for(int t=0;t<4;t++){
            double bx=sx,by=sy;
            if(t&1) bx+=px,by+=py;
            if(t&2) bx+=qx,by+=qy;
            ans=max(ans,bx*bx+by*by);
          }
        }
    }
    ans=sqrt(ans);
    cout.precision(40);
    cout<<ans<<endl;
    
    
}