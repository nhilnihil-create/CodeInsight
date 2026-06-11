#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,M,Q;
    scanf("%d%d%d",&N,&M,&Q);
    vector<vector<int>>group(Q,vector<int>(4));
    
    for(int i=0 ; i<Q ; i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        group.at(i).at(0) = a;
        group.at(i).at(1) = b;
        group.at(i).at(2) = c;
        group.at(i).at(3) = d;
    }
    
    vector<int>A(N,1);
    int e = N-1;
    int sum = 0;
    int current_max=0;
    A.at(e)=0;
    do
    { 
       
        //Aの更新
        sum=0;
        for(int i =0;i<N;i++)
        {
            if(A.at(e-i)!=M)
            {
                A.at(e-i)+=1;
                for(int j =0;j<i;j++)
                {
                    A.at(e-j)=A.at(e-i);
                }
                break;
            }
        }
        //生成されたAについての処理
        for(int i = 0 ; i<Q;i++)
        {
            if(A.at( group.at(i).at(1)-1 )-A.at( group.at(i).at(0)-1 )==group.at(i).at(2) )
            {
                sum+= group.at(i).at(3);
            }
        }
        if(current_max < sum)
        {
            current_max = sum;
        }
    }while(A.at(0)!=M);
    cout<<current_max<<endl;
}   