#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h1,m1,h2,m2,k;
    cin>>h1>>m1>>h2>>m2>>k;
    int h=h2-h1;
    int m=m2-m1;
    cout<< (((h*60)+m)-k)<<endl;


   // if(m<0){
    //    h=-1;
   //     m+=60;
    //}
    //int hourMin=h*60;
    //int res=(hourMin+m)-k;
    //cout<<res<<endl;
}
