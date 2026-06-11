#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;
 
int main(){
    int m,d;cin>>m>>d;
    int ans=0;
    for(int i=1;i<=d;i++){
        int d1=i%10;
        int d10=i/10;
        if(d1<2||d10<2)continue;
        int yay=d1*d10;
        if(yay>0&&yay<=m){ans++;}
    }
    cout<<ans;
}