#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define filein freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);


void fun1(int* a,int* b){
    int sum=*a+*b;
    int dif=abs(*a-*b);
    //cout<<sum<<dif<<"\n";
    *a=sum;
    *b=dif;
}


int main() {


    int n,m;
    cin>>n>>m;
    int a[n];
    double d=(double)1/(4*m);
    //cout<<d<<endl;
    int sum=0;
    for (int i = 0; i <n ; ++i) {

        cin>>a[i];
        sum+=a[i];
    }
    int count=0;
    for (int j = 0; j <n; ++j) {
        double t=(double)a[j]/sum;
        //cout<<t<<endl;
        if (t>=d)
            count++;
    }
    if (count>=m)cout<<"Yes\n";
    else cout<<"No\n";




}
