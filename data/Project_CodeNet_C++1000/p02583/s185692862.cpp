#include <bits/stdc++.h>
using namespace std;

#define print cout <<

template <typename T>
vector<T> getValues(int num);

bool isTriangle(int a, int b, int c);
bool notEqual(int a, int b, int c);

int main(){
    int N;
    cin >> N;
    auto inputs = getValues<int>(N);
    int ans = 0;
    for(int i=0;i<N;i++){
      for(int j=i+1;j<N;j++){
        for(int k=j+1;k<N;k++){
          if(isTriangle(inputs.at(i),inputs.at(j),inputs.at(k))){
            if(notEqual(inputs.at(i),inputs.at(j),inputs.at(k))){
              ans++;
            }
          }
        }
      }
    }
    print ans << endl;

}

template <typename T>
vector<T> getValues(int num){
    vector<T> values(num);
    for(int i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

bool isTriangle(int a, int b, int c){
  if(((a+b)>c) && ((a+c)>b) && ((c+b)>a)){
    return true;
  }
  return false;
}

bool notEqual(int a, int b, int c){
  if(a==b || a==c || b==c){
    return false;
  }
  return true;
}
