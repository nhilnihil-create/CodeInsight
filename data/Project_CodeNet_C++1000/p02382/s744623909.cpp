#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int num;
    double dis1=0,dis2=0,dis3=0,dis4=0,tmp=0;
    cin>>num;
    double vector1[num];
    double vector2[num];
    for(int i=0;i<num;i++) {
        cin >> vector1[i];
    }
    for(int i=0;i<num;i++)
    {
        cin>>vector2[i];
        tmp=abs(vector1[i]-vector2[i]);
        dis1+=tmp;
        dis2+=pow(tmp,2);
        dis3+=pow(tmp,3);
        if(tmp>dis4) dis4=tmp;
    }
    cout<<setiosflags(ios::fixed)<<setprecision(8)<<dis1<<endl<<sqrt(dis2)<<endl<<pow(dis3,0.333333333333333)<<endl<<dis4<<endl;
    return 0;
}
