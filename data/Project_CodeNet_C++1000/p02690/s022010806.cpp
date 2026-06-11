#include <bits/stdc++.h>
using namespace std;
long long int A,B,X,y;
long long int fun(long long int a){
	return a*a*a*a*a;
}
int main()
{
	while(cin>>X)
	{

        int cnt=0;
        for(int i=-1000;i<=1000;i++)
        {
            y=fun(i)+X;
            for(int j=-1000;j<=1000;j++)
            {
                if(fun(j)==y)
                {
                    cout<<j<<" "<<i<<endl;
                    cnt=1;
                    break;
                }
            }
            if(cnt==1)
            {
                break;
            }
        }
	}
	return 0;
}
