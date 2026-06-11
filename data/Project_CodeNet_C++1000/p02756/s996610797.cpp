#include <bits/stdc++.h>
using namespace std;

/* 
 * So basically you want to find the fastest way to perform the operations 
 * Before reading this solution 
 * You should understand how deque works (Google it :D)
 * If you understand how a deque works you should understand this solution 
 * So first thing you should notice is that we don't really need to reverse the whole string 
 * All we need to know is where the front is currently and where the back is currently 
 * So in my code I have a variable swapped 
 * If swapped is true you know that the end has become the front and the front has become the end 
 * So if swapped is true and you get an end operation then it should go to the front and vice-versa 
 * And if swapped isn't true then you should perform the operations as usual 
 * You can look at the code to understand it better 
 * Solution runs in O(Q log n) time
 * Hope this helps!
 */

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  deque<char> deck;
  for (const char& ch : s) 
    deck.push_back(ch);
  int ops;
  cin >> ops;
  bool swapped = false;
  while (ops--) {
    int op;
    cin >> op;
    if (op == 1) swapped = !swapped; // this is just a fancy way of changing the value of swapped (true -> false) and (false -> true)
    else {
      int f;
      char ch;
      cin >> f >> ch;
      if (f == 1) {
        if (swapped)
          deck.push_back(ch); // if swapped this should now go to the back instead of the front 
        else
          deck.push_front(ch); // if not swapped this should go to the front as usual
      } else {
        if (swapped)
          deck.push_front(ch); // if swapped this should now go to the front instead of the back
        else 
          deck.push_back(ch); // if not swapped this should go to the back as usual 
      }
    }
  }
  if (swapped)  // if swapped you need to print the result in reverse
    reverse(deck.begin(), deck.end());
  for (char& ch : deck)
    cout << ch;
  cout << '\n';
  return 0;
}