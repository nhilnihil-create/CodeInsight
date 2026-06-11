#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define Q int tt,qq; cin>>tt ;for(qq=1;qq<=tt;qq++)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main()
{
    double w,h,x,y,a,b;
    cin>>w>>h>>x>>y;
    double area1,area2,area3;
    area1=(double)(w*h)/2;
   // area2=(float)(h-x)*w;
   // area3=(float)h*(w-x);
   // int c=0;
   // if(area1==area2)
   //     c++;
   // if(area1==area3)
   //     c++;
   // if((float)w/2==(float)x && (float)h/2==(float)y)
   //     c++;
   bool ans=false;
   if((double)w/2==(double)x &&(double)h/2==(double)y)
      ans=true;

    cout<<fixed<<setprecision(10)<<area1<<" "<<(1?ans:0)<<endl;
    //cout<<area1;
}