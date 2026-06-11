#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

main(){
  int n;
  set<int> students;
  for(int i=0;i<30;i++) students.insert(i+1);

  for(int i=0;i<28;i++){
    scanf("%d", &n);
    students.erase(students.find(n));
  }

  int a=0,b;

  set<int>::iterator it;
  for(it=students.begin();it!=students.end();it++){
    if(a==0) a = *it;
    else b = *it;
  }
  
  if(a>b){
    swap(a,b);
  }

  printf("%d\n%d\n", a, b);
}