#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int queries; cin >> queries;

	bool is_reversed{ false };
	string extra[2]{ "", "" };
	do
	{
		char op; cin >> op;

		if (op == '1') { is_reversed = !is_reversed; }
		else
		{
			cin >> op;
			char c; cin >> c;

			bool beginning{ op == '1' };
			auto& extra_str{ beginning ? extra[is_reversed] : extra[!is_reversed] };

			if (is_reversed == beginning) { extra_str += c; }
			else { extra_str.insert(extra_str.begin(), c); }
		}

	} while (--queries > 0);

	if (is_reversed)
	{
		reverse(s.begin(), s.end());
		reverse(extra[0].begin(), extra[0].end());
		reverse(extra[1].begin(), extra[1].end());
	}

	cout << extra[is_reversed] << s << extra[!is_reversed] <<  '\n';
}