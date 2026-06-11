#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(void){
    // Your code here!
int n,d;
cin>>n>>d;

vector<vector<int>> vec(n+1, vector<int>(d+1));

for(int i=1;i<=n;i++){
    for(int j=1;j<=d;j++){
        cin>>vec[i][j];
    }
}

int answer=0;
for(int i=1;i<=n-1;i++){
    for(int j=i+1;j<=n;j++){
            long double ans=0;
            for(int k=1;k<=d;k++){
                    ans+=pow((vec[i][k]-vec[j][k]),2);
            }
            ans= sqrt(ans);
            if(ans==(int)ans)
             answer++;   
        }
    }

cout<<answer;
}
