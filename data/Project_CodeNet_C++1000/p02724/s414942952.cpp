 #include<iostream>
#define ll long long

int main(){
ll x;
  std::cin >> x;
ll t=0;
  t+=(x/500)*1000;
  x=(x%500);
  t+=(x/5)*5;
  std::cout << t << std::endl;
return 0;
}
