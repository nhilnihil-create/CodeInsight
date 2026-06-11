  #include<bits/stdc++.h>
    using namespace std;
    using Int = long long;
    template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
    template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
     
    //INSERT ABOVE HERE
    signed main(){
      Int n;
      cin>>n;
      vector<Int> xs(n),ys(n);
      for(Int i=0;i<n;i++) cin>>xs[i]>>ys[i];
     
      using D = double;
      D ans=0;
      for(Int i=0;i<n;i++){
        Int gx=xs[i],gy=ys[i];
        for(Int k=0;k<4;k++){
          {
            Int nx=-gy,ny=gx;
            gx=nx;
            gy=ny;
          }
     
          Int sx=0,sy=0;
          Int px=0,py=0;
          Int qx=0,qy=0;
     
          auto dot=[&](Int x1,Int y1,Int x2,Int y2){return x1*x2+y1*y2;};
          auto cross=[&](Int x1,Int y1,Int x2,Int y2){return x1*y2-x2*y1;};
          for(Int j=0;j<n;j++){
            Int res=dot(xs[j],ys[j],gx,gy);
            if(res<0) continue;
            if(res>0){
              sx+=xs[j];
              sy+=ys[j];
              continue;
            }
            if(cross(xs[j],ys[j],gx,gy)>0){
              px+=xs[j];
              py+=ys[j];
            }else{
              qx+=xs[j];
              qy+=ys[j];
            }
          }
     
          for(Int t=0;t<4;t++){
            D bx=sx,by=sy;
            if(t&1) bx+=px,by+=py;
            if(t&2) bx+=qx,by+=qy;
            chmax(ans,bx*bx+by*by);
          }
        }
      }
     
      cout<<fixed<<setprecision(12)<<sqrt(ans)<<endl;
      return 0;
    }