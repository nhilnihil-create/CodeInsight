#include <iostream>

using namespace std;

int getNext(int n,int m,int maxrank){
  int max;
  int min = 0;
  int nums[6];
  int insmaxrank = maxrank;
  int minrank = 1;
  int num;
  max = n;
  for(int i=0;i<m;i++){
    nums[i] = max % 10;
    max /= 10;
  }

  max = 0;
  for(int i=0;i<m;i++){
    int insmax = 0;
    int index;
    for(int j=0;j<m;j++){
      if(insmax < nums[j]){
        insmax = nums[j];
        index = j;
      }
    }
    nums[index] = 0;
    max += insmax*insmaxrank;
    insmaxrank /= 10;
  }
  num = max;
  for(int i=0;i<m;i++){
    min += (num%10)*maxrank;
    maxrank /= 10;
    minrank *= 10;
    num /= 10;
  }
  return max - min;
}

int getAns(int ans[],int n){
  for(int i=0;i<20;i++){
    if(ans[i] == n) return i;
  }
  return -1;
}

int main(){
  int n,m;
  cin >> n >> m;
  do{
    int ans[20];
    for(int i=0;i<20;i++) ans[i] = -1;
    int maxrank = 1;
    int next = n;
    int count=0;
    for(int i=0;i<m-1;i++) maxrank *= 10;
    while(getAns(ans,next) == -1){
      if(count < 20) ans[count] = next;
      next = getNext(next,m,maxrank);
      count++;
    }
    cout << getAns(ans,next) << " " << next << " " << count - getAns(ans,next) << endl;
    cin >> n >> m;
  }while(n != m && m != 0);
}