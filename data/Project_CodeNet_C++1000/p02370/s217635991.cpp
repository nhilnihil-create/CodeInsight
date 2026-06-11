#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> nodes[100100];
int pre[100100] = {0};
int post[100100] = {0};
int ith = 0;
stack<int> re;
void topo(int s)
{
   pre[s] = ++ith;
   for (auto i : nodes[s])
   {
      if (!pre[i])
      {
         topo(i);
      }
   }
   re.push(s);
}
int main()
{
   int e, n;
   cin >> n >> e;
   for (int i = 0; i < e; ++i)
   {
      int x, y;
      cin >> x >> y;
      nodes[x].push_back(y);
   }
   for (int i = 0; i < n; ++i)
   {
      if (!pre[i])
      {
         topo(i);
      }
   }
   while(!re.empty()){
      cout << re.top() << "\n";
      re.pop();
   }
}
