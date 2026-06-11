#include<bits/stdc++.h>
#include<math.h>
using namespace std;

typedef struct{
    double x;
    double y;
}xy;
void kock(int,xy,xy);

int main(){
    xy p1={0.00,0.00},p2={100.000,0.00};
    int n;

    cin>>n;
    cout<<p1.x<<" "<<p1.y<<endl;
    kock(n,p1,p2);
    cout<<p2.x<<" "<<p2.y<<endl;


    return 0;
}

void kock(int n,xy p1,xy p2){
    xy s,t,u;
    if(n==0)return;
    s.x=(2*p1.x+p2.x)/3;
    s.y=(2*p1.y+p2.y)/3;
    t.x=(p1.x+2*p2.x)/3;
    t.y=(p1.y+2*p2.y)/3;
    u.x=(t.x-s.x)/2-(t.y-s.y)*sqrt(3)/2+s.x;
    u.y=(t.x-s.x)*sqrt(3)/2+(t.y-s.y)/2+s.y;


    kock(n-1,p1,s);
    cout<<s.x<<" "<<s.y<<endl;
    kock(n-1,s,u);
    cout<<u.x<<" "<<u.y<<endl;
    kock(n-1,u,t);
    cout<<t.x<<" "<<t.y<<endl;
    kock(n-1,t,p2);

}
