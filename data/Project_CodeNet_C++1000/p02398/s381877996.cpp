#include <iostream>
using namespace std;

int main(){
    int a,b,c,i,ans;
    cin >>a>>b>>c;
    for (i=a;i<=b;i++){
      if (!(c%i))ans++;
    }
    cout<<ans<<endl;
    return 0;
}

