#include<bits/stdc++.h>
using namespace std;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);cout.tie(NULL);
        int x;
        cin>>x;
        for(int j=1;j<=8;j++){
                if(x>=2000-200*j && x<2000-200*(j-1)){
                        cout<<j;
                }
        }
return 0;
}
/*

        creation time:  15.09.2020 11:04:53

*/                      

