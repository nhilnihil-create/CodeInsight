#include <iostream>
#include <queue>
#include <vector>

#define MAXSIZE 100000

using namespace std;

void calculate(vector<long long int>& lunlun_num)
{
  queue<long long int> lunlun_temp;
  for (int i = 1; i <= 9; i++){
    lunlun_temp.push(i);
    lunlun_num.push_back(i);
  }
  int count = 9;
  while (count <= MAXSIZE){
    long long int temp = lunlun_temp.front(), num = temp * 10 + temp % 10;
    lunlun_temp.pop();
    if (temp % 10 != 0){
      lunlun_temp.push(num - 1);
      lunlun_num.push_back(num - 1);
      count++;
    }
    lunlun_temp.push(num);
    lunlun_num.push_back(num);
    count++;
    if (temp % 10 != 9){
      lunlun_temp.push(num + 1);
      lunlun_num.push_back(num + 1);
      count++;
    }
  }
}

void getans(vector<long long int>& lunlun_num)
{
  int index;
  cin >> index;
  cout << lunlun_num[index - 1] << '\n';
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<long long int> lunlun_num;
  calculate(lunlun_num);
  getans(lunlun_num);
  return 0;
}
