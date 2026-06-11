#include<iostream>
#include<iomanip>
#include<cmath>
void kock(int, std::pair<double,double>, std::pair<double,double>);
int main(){
  int n;
  std::pair<double,double> p1=std::make_pair(0,0), p2=std::make_pair(100,0);
  std::cin >> n;
  std::cout << std::fixed << std::setprecision(10) << p1.first << " " << p1.second << std::endl;
  kock(n,p1,p2);
  std::cout << std::fixed << std::setprecision(10) << p2.first << " " << p2.second << std::endl;
  return 0;
}
void kock(int n, std::pair<double,double> p1, std::pair<double,double> p2){
  std::pair<double,double> s,t,u;
  if(n == 0) return;
  s.first = (2 * p1.first + 1 * p2.first) / 3;
  s.second = (2 * p1.second + 1 * p2.second) / 3;
  t.first = (1 * p1.first + 2 * p2.first) / 3;
  t.second = (1 * p1.second + 2 * p2.second) / 3;
  u.first = (t.first - s.first) * cos(M_PI/3) - (t.second - s.second) * sin(M_PI/3) + s.first;
  u.second = (t.first - s.first) * sin(M_PI/3) + (t.second - s.second) * cos(M_PI/3) + s.second;
  kock(n-1, p1, s);
  std::cout << std::fixed << std::setprecision(10) << s.first << " " << s.second << std::endl;
  kock(n-1, s, u);
  std::cout << std::fixed << std::setprecision(10) << u.first << " " << u.second << std::endl;
  kock(n-1, u, t);
  std::cout << std::fixed << std::setprecision(10) << t.first << " " << t.second << std::endl;
  kock(n-1, t, p2);
}