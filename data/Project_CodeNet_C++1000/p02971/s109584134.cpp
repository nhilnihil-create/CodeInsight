#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnSeq)
{
  int nSeqSiz;
  cin >> nSeqSiz;
  rvnSeq.resize(nSeqSiz);

  for (int& rnSeq : rvnSeq)
    cin >> rnSeq;
}
  
void fnSeqMaxNum(const vector<int>& cnrvnSeq, vector<int>& rvnMax)
{
  vector<int> vnSrtSeq(cnrvnSeq);
  sort(begin(vnSrtSeq), end(vnSrtSeq));

  for (int i = 0; i < cnrvnSeq.size(); i++)
    if (cnrvnSeq[i] == vnSrtSeq[vnSrtSeq.size() - 1])
      rvnMax.push_back( vnSrtSeq[vnSrtSeq.size() - 2] );
    else
      rvnMax.push_back( vnSrtSeq[vnSrtSeq.size() - 1] );
}
  
int main()
{
  vector<int> vnSeq, vnMax;

  fnInput(vnSeq);
  fnSeqMaxNum(vnSeq, vnMax);

  for (int nMax : vnMax)
    cout << nMax << endl;

  return 0;
}