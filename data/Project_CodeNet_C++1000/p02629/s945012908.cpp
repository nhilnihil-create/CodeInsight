#include<iostream>
using namespace std;
  
  char converter[26];
  
  char letter(int n){
    char l = 'a' + n - 1;
    return l;
    
  }
  
  char format[100];

int main(){
  
  unsigned long long n; cin >> n;
  int index = 0;
  while(n>0){
    int temp = n%26;
    if(temp==0)temp = 26;
    format[index++] = letter(temp);
    n/=26;
    if(temp==26)n--;
    
  }
  format[index] = '\n';
  for(int i=index-1;i>=0;i--)printf("%c",format[i]);
  printf("\n");
  
  return 0;
}