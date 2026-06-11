#include <iostream>

using namespace std;

int main()
{
  int a, b, m;
  int re[100010], de[100010];
  int x[100010], y[100010], c[100010];
  int remin = 200010, demin = 200010;
  
  cin >> a >> b >> m;
  for (int i = 0; i < a; i++) {
    cin >> re[i];
    if (remin > re[i]) {
      remin = re[i];
    }
  }
  for (int i = 0; i < b; i++) {
    cin >> de[i];
    if (demin > de[i]) {
      demin = de[i];
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i] >> c[i];
  }
  
  int min = demin + remin;
  
  for (int i = 0; i < m; i++) {
    if (min > re[x[i]-1] + de[y[i]-1] - c[i]) {
      min = re[x[i]-1] + de[y[i]-1] - c[i];
    }
  }
  
  cout << min << endl;
}
        