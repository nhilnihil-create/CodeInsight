#include <iostream>
#include <string>
using namespace std;

int main() {

  int n;
  cin >> n;
  for(int q=0;q<n;q++) {

    
    string a,b,t1,t2;
   
    cin >> t1 >> t2;
    a = b = "1";
    a+= t1;
    b+= t2;
    //m=1000,c=100,x=10,i=1;

    int ra= 0;
    int flg = 0;
    for(int i=1;i<a.size();i++){
      if(a[i] == 'm') flg = 1000;
      else if(a[i] == 'c') flg =100;
      else if(a[i] == 'x') flg = 10;
      else if(a[i] == 'i') flg = 1;
      else continue;
      
      if('2'<=a[i-1] && a[i-1]<='9')ra += flg*(a[i-1]-'0');
      else ra += flg;
    }

    int rb=0;
    for(int i=1;i<b.size();i++){
      if(b[i] == 'm') flg = 1000;
      else if(b[i] == 'c') flg =100;
      else if(b[i] == 'x') flg = 10;
      else if(b[i] == 'i') flg = 1;
      else continue;
      
      if('2'<=b[i-1] && b[i-1]<='9')rb += flg*(b[i-1]-'0');
      else rb += flg;
    }

    //    cout << ra <<" "<<rb<<endl;
    int sum = ra + rb;
    string ans;
    while(sum !=0){
      if(sum >= 1000) flg = 1000;
      else if(sum >= 100) flg = 100;
      else if(sum >= 10) flg = 10;
      else if(sum >= 1) flg =1;
      
      if(sum/flg !=1) ans += sum/flg+'0';

      if(flg == 1000) ans+= 'm';
      else if(flg == 100) ans +='c';
      else if(flg == 10) ans += 'x';
      else if(flg == 1) ans += 'i';
      
      sum %= flg;
    }
    cout << ans <<endl;

  }

  return 0;
}
      
    