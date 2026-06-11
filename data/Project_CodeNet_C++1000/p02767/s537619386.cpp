#include<iostream>

int main(){
int n;
 std::cin >> n;
 int a[n];
 int avg=0;
 for(int i=0;i<n;i++){
       std::cin >> a[i];
       avg+=a[i];
 }
 int avg1=avg;
 avg=(avg)/n;
 avg1=(avg1+n-1)/n;
 //std::cout << avg << " " << avg1 << "\n";
 int t=0,t1=0;
 for(int i=0;i<n;i++){
     t+=(a[i]-avg)*(a[i]-avg);
     t1+=(a[i]-avg1)*(a[i]-avg1);
 }
 std::cout << std::min (t,t1) << std::endl;
 return 0;
}
