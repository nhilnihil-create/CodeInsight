#include<bits/stdc++.h>
using namespace std;
#define For(start,end) for(int i = (int)start;i<(int)end;i++)
using Int = long long int;
using TDim = vector<vector<int>>;
int main(){
    int L,R;
    cin>>L>>R;
    int modL=L%2019,modR = R%2019;
    bool check=(L/2019)!=(R/2019);
    if(modL>modR||check)cout<<0<<endl;
    else
    {
        int min = 2019;
        for(int tmpL=modL;tmpL<=modR-1;tmpL++)
        {

      
            for(int tmpR=tmpL+1;tmpR<=modR;tmpR++)
            {
                int current = (tmpL*tmpR)%2019;
                if(min>current)
                {
                    min=current;
                }
            }
            
           
        }
        cout<<min<<endl;

    }
}
