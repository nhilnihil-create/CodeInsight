#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n,ans;

int main (){
	scanf("%d",&n);
  	for(int i = 1;i <= n;i++){
      if(360 * i % n == 0){
        printf("%d\n",360*i/n);
        return 0;
      }
    }
  return 0;
}
