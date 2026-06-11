#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int main(){
  int n;
  int *s;
  vector<double> out;
  while(1){
    scanf("%d", &n);
    if(n == 0)
      break;
    else{
      s = new int[n];
      double a = 0;
      for(int i = 0; i < n; i++){
	scanf("%d", &s[i]);
	a += s[i];
      }
      double avg = a / n;
      double k = 0;
      for(int i = 0; i < n; i++){
	double j = s[i] - avg;
	k += j * j;
      }
      double var = k / n;
      out.push_back(sqrt(var));
      delete[] s;
    }
  }
  while(!out.empty()){
    printf("%.8f\n", out.front());
    out.erase(out.begin());
  }
  return 0;
}