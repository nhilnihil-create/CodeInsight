// Lec10-C Standard Deviation
#include<iostream>
#include<cmath>
#include<iomanip>
double std_dev(int, int[]);
int main(){
  int n, *scr;
  while(std::cin >> n){
    if(!n) break;
    scr = new int[n];
    for(int i=0; i<n; i++) std::cin >> scr[i];
    std::cout << std::fixed << std::setprecision(8) << std_dev(n, scr) << std::endl;
    delete(scr);
  }
}
double std_dev(int n, int scr[]){
  double ave=0, a=0;
  for(int i=0; i<n; i++) ave += scr[i];
  ave /= n;
  for(int i=0; i<n; i++) a += pow(scr[i]-ave, 2);
  return sqrt(a/n);
}