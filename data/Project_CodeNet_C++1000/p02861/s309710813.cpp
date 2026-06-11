#include<bits/stdc++.h>
using namespace std;

int sqr(int x){
    return x*x;
}

double dist(int x,int y){
    return sqrt(sqr(x)+sqr(y));
}

int main()
{
    int n;
    cin>>n;
    vector<int> x;
    vector<int> y;
    vector<int> m;
    double sum=0;
    int cnt=0;
    for (int i=0;i<n;++i)
    {
        int tempx,tempy;
        cin>>tempx>>tempy;
        x.push_back(tempx);
        y.push_back(tempy);
        m.push_back(i);
    }
    do{
        for(int i=0;i<n-1;i++)
        {
            sum+=dist(x[m[i]]-x[m[i+1]],y[m[i]]-y[m[i+1]]);
        }
        cnt++;
    }while(next_permutation(m.begin(),m.end()));
    cout<<fixed<<setprecision(8)<<sum/cnt<<endl;
}