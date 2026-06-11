#include<bits/stdc++.h>
using namespace std;
int gcc(int a,int b)
{
    if(a%b==0)return b;
    return gcc(b,a%b);
}
int main()
{
    int K;
    cin>>K;
    vector<int>A(3,1);
    A.at(0)=0;
    int sum=0;
    do
    {
        
        
        if(A.at(0)==K)
        {
            if(A.at(1)==K)
            {
                A.at(0)=1;
                A.at(1)=1;
                A.at(2)+=1;
            }
            else
            {
                A.at(0)=1;
                A.at(1)+=1;
            }
            
        }else{
            A.at(0)+=1;
        }
        
        sum+=gcc(gcc(A.at(0),A.at(1)),A.at(2));
    }while(A.at(0)+A.at(1)+A.at(2)!=K*3);
    cout<<sum<<endl;
}