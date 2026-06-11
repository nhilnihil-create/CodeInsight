#include <vector>
#include <cstddef>

template<class T>
struct fenwick_tree {
	using value_type = T;
	using size_type = std::size_t;
private :
	std::vector<T> node;
public :
	fenwick_tree (size_type n) : node(n, 0) { }

	const size_type size () const noexcept {
		return node.size();
	}

	void add (size_type index, const T &value) noexcept {
		index++;
		while (index <= size()) {
			node[index - 1] += value;
			index += (index & -index);
		}
	}

	value_type sum (size_type last) const noexcept {
		value_type value = 0;
		while (last > 0) {
			value += node[last - 1];
			last -= (last & -last);
		}
		return value;
	}

	value_type sum (size_type first, size_type last) const noexcept {
		return (sum(last) - sum(first));
	}

};

#include <iostream>

using usize = std::size_t;

int main() {
	usize n, q;
	std::cin >> n >> q;
	fenwick_tree<long long> ft(n);
	for (usize i = 0; i < n; i++) {
		long long a;
		std::cin >> a;
		ft.add(i, a);
	}
	
	for (usize _ = 0; _ < q; _++) {
		usize type;
		std::cin >> type;
		if (type == 0) {
			usize index;
			long long x;
			std::cin >> index >> x;
			ft.add(index, x);
		} else {
			usize l, r;
			std::cin >> l >> r;
			std::cout << ft.sum(l, r) << '\n';
		}
	}
	
	return 0;
}