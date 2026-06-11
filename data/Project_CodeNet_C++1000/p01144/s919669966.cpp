#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct DATA{
  int d;
  int p;
};

bool Compare(const DATA&, const DATA&);

int main(){
  int i, n, m, d, p, sum;
  DATA _data;
  vector<DATA> data;

  while(1){
    cin >> n >> m;
    if(n == 0 && m == 0) break;

    for(i=0; i<n; ++i){
      cin >> d >> p;
      _data.d = d;
      _data.p = p;
      data.push_back(_data);
    }
    sort(data.begin(), data.end(), Compare);

    while(data.size() != 0){
      if(m > data[0].d){
	m -= data[0].d;
	data.erase(data.begin());
      }else{
	data[0].d -= m;
	break;
      }
    }

    for(i=0, sum=0; i<data.size(); ++i)
      sum += data[i].d * data[i].p;

    cout << sum << endl;
    data.clear();
  }
  return 0;
}

bool Compare(const DATA& x, const DATA& y){
  if(x.p == y.p)
    return x.d < y.d;
  else
    return x.p > y.p;
}