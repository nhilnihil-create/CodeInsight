#include <iostream>
#include <vector>
using namespace std;


int main()
{
  int N;
  cin >> N;
  vector<int> P;
  for(int i=0;i<N;i++){
    P.push_back(i+1);
  }

  int num=0;
  for(int i=0;i<N;i++){
    int p;
    cin >> p;
    if(p !=i+1){
      num ++;
    }
    
  }
  if((num==0)||(num==2)){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }

}