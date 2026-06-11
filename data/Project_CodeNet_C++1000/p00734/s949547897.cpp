#include<iostream>
#include<vector>
using namespace std;
int main(){
    while(1){
        int n,m,x,sum1=0,sum2=0,ans=100000,num,ax=0,ay=0;
        vector<int> N,M;
        cin >> n >> m;
        if(n==0&&m==0)  break;
        for(int i=n;i--;){
            cin >> x;
            sum1+=x;
            N.push_back(x);
        }
        for(int i=m;i--;){
            cin >> x;
            sum2+=x;
            M.push_back(x);
        }
        num = sum1 - sum2;
        //cout << sum1 << " " <<sum2 << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(num == 2*(N[i]-M[j])&&ans>N[i]+M[j]){
                    ans = N[i]+M[j];
                    ax=N[i];
                    ay=M[j];
                }
            }
        }
        if(ax==0&&ay==0)    cout << "-1\n";
        else cout << ax << " " << ay << "\n";
    }
}