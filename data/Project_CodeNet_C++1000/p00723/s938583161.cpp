#include<iostream>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

void OrganizeTrain(set<string>&, string, int);
string Reverse(string);

int main(){
  int i, j, n;
  string str;
  set<string> data;

  cin >> n;

  for(i=0; i<n; ++i){
    cin >> str;

    for(j=1; j<str.size(); ++j)
      OrganizeTrain(data, str, j);

    cout << data.size() << endl;
    data.clear();
  }
  return 0;
}

void OrganizeTrain(set<string>& data, string original, int n){
  string front, back;
  string reverse_front, reverse_back;

  copy(original.begin(), original.begin()+n, back_inserter(front));
  copy(original.begin()+n, original.end(), back_inserter(back));
  reverse_front = Reverse(front);
  reverse_back = Reverse(back);

  if(data.find(front + back) == data.end())
    data.insert(front + back);
  if(data.find(front + reverse_back) == data.end())
    data.insert(front + reverse_back);

  if(data.find(reverse_front + back) == data.end())
    data.insert(reverse_front + back);
  if(data.find(reverse_front + reverse_back) == data.end())
    data.insert(reverse_front + reverse_back);

  if(data.find(back + front) == data.end())
    data.insert(back + front);
  if(data.find(back + reverse_front) == data.end())
    data.insert(back + reverse_front);

  if(data.find(reverse_back + front) == data.end())
    data.insert(reverse_back + front);
  if(data.find(reverse_back + reverse_front) == data.end())
    data.insert(reverse_back + reverse_front);
}

string Reverse(string str){
  int i;
  string _str;
  for(i=str.size()-1; i>=0; --i) _str.push_back(str[i]);
  return _str;
}