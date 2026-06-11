# include <iostream>
# include <vector>
# include <map>
using namespace std;

# define ll long long

bool allZero(vector<int> numbers){
  for(int num : numbers){
    if(num != 0) return false;
  }
  return true;
}

bool checkTypeOne(vector<int> numbers){
  if(numbers.size() % 3 != 0) return false;
  int zero = 0;
  for(int num : numbers)
    if(num == 0) zero++;
  
  if(zero == numbers.size()/3) return true;
  else return false;
}

bool checkTypeTwo(vector<int> numbers){
  if(numbers.size() % 3 != 0) return false;
  map<int,int> frequency;
  for(int num : numbers) frequency[num]++;
  if(frequency.size() != 3) return false;
  
  int result = 0;
  for(auto keyValue : frequency){
    int key = keyValue.first;
    int value = keyValue.second;
    if(value != numbers.size()/3) return false;
    result ^= key;
  }
  
  if(result == 0) return true;
  else return false;
}

int main(){
  int n;
  cin >> n;
  
  vector<int> numbers(n);
  for(int i=0; i<n; i++) cin >> numbers[i];
  
  bool possible;
  if(allZero(numbers) || checkTypeOne(numbers) || checkTypeTwo(numbers)) possible = true; 
  else possible = false;
  
  cout << (possible ? "Yes" : "No") << endl;
  
  return 0;
} 

