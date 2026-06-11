#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	char ch;
	while (ch = getchar(), ch != '.') {
		stack<int> st;
		bool flag = true;
		while (ch != '\n') {
			if (ch == '[') {
				st.push(1);
			} else if(ch == '(') {
				st.push(2);
			} else if(ch == ']') {
				if (!st.empty() && st.top() == 1)
					st.pop();
				else
					flag = false;
			} else if(ch == ')') {
				if (!st.empty() && st.top() == 2)
					st.pop();
				else
					flag = false;
			}
			ch = getchar();
		}
		if (!st.empty())
			flag = false;
		if (flag)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}